def my_var():
    t1 = 42
    t2 = "42"
    t3 = "quarante-deux"
    t4 = 42.0
    t5 = True
    t6 = [42]
    t7 = {42 : 42}
    t8 = (42, )
    t9 = set()
    s = "has a type"

    lst = [t1, t2, t3, t4, t5, t6, t7, t8, t9]

    for t in lst:
        print(t, s, type(t))


if __name__ == '__main__':
    my_var()