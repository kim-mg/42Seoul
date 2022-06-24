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
    s = "is the capital of"
    ns = "is neither a capital city nor a state"
    if (len(lst) != 2):
        exit(1)
    lst = list(map(lambda x: x.strip(), lst[1].split(", ")))

    for t in lst:
        if t == "":
            continue
        elif t.title() in states.keys():
            print(t, s, capital_cities[states[t.title()]])
        elif t.title() in capital_cities.values():
            print(t, s, list(states.keys())[list(states.values()).index(list(capital_cities.keys())[list(capital_cities.values()).index(t.title())])])
        else:
            print(t, ns)

if __name__ == '__main__':
    solution()