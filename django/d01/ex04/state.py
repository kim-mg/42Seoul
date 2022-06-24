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
    elif lst[1] not in capital_cities.values():
        print("Unknown capital city")
        exit(1)
    else:
        print(list(states.keys())[list(states.values()).index(list(capital_cities.keys())[list(capital_cities.values()).index(lst[1])])])

if __name__ == '__main__':
    solution()