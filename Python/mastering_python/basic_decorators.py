# Decorator
"""
    Given spam a fn. and eggs a deco
    spam = eggs(spam)
    def eggs(function):
        return function
    @eggs
    def spam():
        pass

"""
"""
    Sample Decorator

"""

import functools
# Decorator Function


def print_all_input(function):
    @functools.wraps(function)
    def aeggs(*args, **kwargs):
        print ("args are ", args)
        print ('$' * 10)
        print ("kwargs are ", kwargs)

        print ("NAME OF Function is", function.__name__)

        return function(*args, **kwargs)
    return aeggs
# Normal func


@print_all_input
def spam(a, b, c):
    return a + b + c

print (spam(1, 2, 3))

"""
How decorators used in debug

import somemodule
debug_this_function=debug(somemodule.somefunc)
get debugoutput
debug_this_function()

also
somemodule.somefunc= debug_this_function
Now when u call somemodule.somefunc u will get decorated out
"""


def plus_one(function):
    @functools.wraps(function)
    def _plus_one(self, n):
        return function(self, n + 1)
    return _plus_one


class Spam(object):
    def __init__(self):
        pass

    @plus_one
    def somefunc(self, n):
        print (n)

Spam().somefunc(1)


"""
class method and staticmethod
classmethod passes object and static method skips both instance and object


"""
print ("$" * 10)


class Spam(object):
    def __init__(self):
        pass

    def some_instance(self, *args, **kwargs):
        print ('args ', args)
        print ('kwargs ', kwargs)
        print ('self ', self)

    @classmethod
    def some_cls_method(cls, *args, **kwargs):
        print ('args ', args)
        print ('kwargs ', kwargs)
        print ('cls ', cls)

    @staticmethod
    def some_gen_method(*args, **kwargs):
        print ('args ', args)
        print ('kwargs ', kwargs)


spam = Spam()
spam.some_instance(1, 2, a=5, b=6)
# Spam.some_instance() will through an error
print (spam.some_cls_method(1, 2, a=2, b=3))
Spam.some_cls_method()
"""
args  ()
kwargs  {}
cls  <class '__main__.Spam'>

"""
"""
    Extra Arguments in decorator


"""
print ('$' * 10)


def add(extra_n=5):

    def _add(function):
        @functools.wraps(function)
        def __add(n):
            print ("hey ", extra_n, n)
            return function(n + extra_n)
        return __add
    return _add


@add(7)
@add(2)
def spam(n):
    return n
print (spam(5))
