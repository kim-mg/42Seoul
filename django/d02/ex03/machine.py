#!/usr/bin/python3

import random
from beverages import *

class CoffeeMachine():

    def __init__(self):
        self.count = 0

    class EmptyCup(HotBeverage):
        def __init__(self):
            self.name = "empty cup"
            self.price = 0.90

        def description(self):
            return  "An empty cup?! Gimme my money back!"

    class BrokenMachineException(Exception):
            def __init__(self):
                super().__init__("This coffee machine has to be repaired.")
    
    def repair(self):
        self.count = 0

    def serve(self, beverage: HotBeverage):
        if self.count < 10:
            self.count += 1
            if beverage not in [Coffee, Tea, Chocolate, Cappuccino]:
                return random.choice([str(beverage.__name__) + " not in menu", self.EmptyCup()])
            else:
                return random.choice([beverage(), self.EmptyCup()])
        else:
            return CoffeeMachine.BrokenMachineException()

if __name__ == '__main__':
    lst = [Coffee, Tea, Chocolate, Cappuccino]
    a = CoffeeMachine()
    for i in range(20):
        if i == 11:
            a.repair()
        print(a.serve(random.choice(lst)), "\n")