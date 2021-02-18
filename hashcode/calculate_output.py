import os.path
import math

BOOK_SCORES =[]
LIBRARIES = []
NUM_DAYS = 0

class Library:
    def __init__(self, id, book_ids, signup_days, max_books_scanned_per_day):
        self.id = id
        self.book_ids = book_ids
        self.books_with_score = self.calculate_books_with_score()
        self.signup_days = signup_days
        self.max_books_scanned_per_day = max_books_scanned_per_day
        self.available_days = self.calculate_available_days()
        self.library_score = self.calculate_score()

    def calculate_books_with_score(self):
        books_with_scores = []
        for book_id in self.book_ids:
            books_with_scores.append((book_id, BOOK_SCORES[book_id]))
        return sorted(books_with_scores, key=lambda b: b[1], reverse=True)


    def calculate_available_days(self):
        return NUM_DAYS - self.signup_days

    def calculate_book_score(self):
        k = self.available_days * self.max_books_scanned_per_day
        return sum(map(lambda b: b[1], self.books_with_score[:k]))
    
    def calculate_score(self):
        return self.calculate_book_score() / self.signup_days 

    def __repr__(self):
        return str(self.id)
    
def get_info(fpath):
    with open(fpath) as f:
        global NUM_DAYS, BOOK_SCORES, LIBRARIES
        num_books, num_libraries, NUM_DAYS = list(map(int, f.readline().split(" ")))
        BOOK_SCORES = list(map(int, f.readline().split(" ")))  
        
        for i in range(num_libraries):
            books_inlib, signupdays, books_ship_oneday =list(map(int, f.readline().split(" ")))
            book_ids = list(map(int, f.readline().split(" ")))
            LIBRARIES.append(Library(i, book_ids, signupdays, books_ship_oneday))

def calculate_score(fpath):
    total_score = 0
    books_scanned = set()
        
    with open(fpath) as f:
        num_library = int(f.readline())
        days_past = 0
        for i in range(num_library):
            lib_index, num_books = list(map(int, f.readline().split(" ")))
            books = list(map(int, f.readline().split()))
            days_past += LIBRARIES[lib_index].signup_days
            available_days = NUM_DAYS - days_past
            num_books_scanned = int(math.ceil(available_days * LIBRARIES[lib_index].max_books_scanned_per_day))
            books = books[:num_books_scanned]
            books_scanned.update(books)
            #breakpoint()
    # books_scanned là tất cả các unique book đc scan
    #breakpoint()
    for book_id in books_scanned:
        total_score += BOOK_SCORES[book_id]
        
    return total_score

print("Program start")
get_info('input/a_example.txt')
LIBRARIES = sorted(LIBRARIES, key=lambda l: l.library_score, reverse=True)
print(LIBRARIES)
#print(calculate_score('output/b_example.txt'))
#print(NUM_DAYS, BOOK_SCORES)