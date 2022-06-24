import sys

def solution():
    states = {
    "Oregon" : "OR",
    "Alabama" : "AL",
    "New Jersey": "NJ",
    "Colorado" : "CO"
    }
    capital_cities = {
    "OR": "Salem",
    "AL": "Montgomery",
    "NJ": "Trenton",
    "CO": "Denver"
    }

    lst = sys.argv

    if (len(lst) != 2):
        exit(1)
    elif lst[1] not in states:
        print("Unknown state")
        exit(1)
    else:
        print(capital_cities[states[lst[1]]])

if __name__ == '__main__':
    solution()