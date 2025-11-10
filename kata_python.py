# def trailing_zeros(number):
#     if number < 100:
#         return False
#     s = str(number)
#     for i in range(len(s)):
#         if i == 0:
#             continue
#         if s[i] != '0':
#             return False
#
#     return True
#
# def is_palindrome(number):
#     if number < 100:
#         return False
#     s = str(number)
#     istart = 0
#     iend = len(s) - 1
#
#     while True:
#         if s[istart] == s[iend]:
#             istart += 1
#             iend -= 1
#             if istart >= iend:
#                 return True
#         else:
#             return False
#
# def is_monotone(number):
#     if number < 100:
#         return False
#     s = str(number)
#     for i in range(len(s)):
#         if s[0] != s[i]:
#             return False
#
#     return True
#
# def is_sequential_incr(number):
#     if number < 100:
#         return False
#     s = str(number)
#     num = int(s[0])
#     for i in range(len(s)):
#         if str(num) != s[i]:
#             return False
#         num += 1
#         if num > 9:
#             num = 0
#     return True
#
# def is_sequential_decr(number):
#     if number < 100:
#         return False
#     s = str(number)
#     num = int(s[0])
#     for i in range(len(s)):
#         if str(num) != s[i]:
#             return False
#         num -= 1
#         # if num < 0:
#         #     num = 9
#     return True
#
# def is_interesting(number, awesome_phrases):
#     if number < 10:
#         return 0
#     if number in awesome_phrases:
#         return 2
#     if trailing_zeros(number) or is_palindrome(number) or is_monotone(number) or is_sequential_incr(number) or is_sequential_decr(number):
#         return 2
#     number += 1
#     if number in awesome_phrases:
#         return 1
#     if trailing_zeros(number) or is_palindrome(number) or is_monotone(number) or is_sequential_incr(number) or is_sequential_decr(number):
#         return 1
#     number += 1
#     if number in awesome_phrases:
#         return 1
#     if trailing_zeros(number) or is_palindrome(number) or is_monotone(number) or is_sequential_incr(number) or is_sequential_decr(number):
#         return 1
#
#     return 0
#
# def test_():
#     # assert is_palindrome(121) == True
#     # assert is_palindrome(1221) == True
#     # assert is_palindrome(1231) == False
#     #
#     # assert is_monotone(1234) == False
#     # assert is_monotone(111) == True
#     #
#     # assert is_sequential_incr(12345) == True
#     # assert is_sequential_incr(12346) == False
#     # assert is_sequential_decr(98765) == True
#     # assert is_sequential_decr(98754) == False
#
#     # assert is_interesting(799999, []) == 1
#     assert is_interesting(109, []) == 1
#
#
#
# test_()
# # import test
# # tests = [
# #     {'n': 3, 'interesting': [1337, 256], 'expected': 0},
# #     {'n': 1336, 'interesting': [1337, 256], 'expected': 1},
# #     {'n': 1337, 'interesting': [1337, 256], 'expected': 2},
# #     {'n': 11208, 'interesting': [1337, 256], 'expected': 0},
# #     {'n': 11209, 'interesting': [1337, 256], 'expected': 1},
# #     {'n': 11211, 'interesting': [1337, 256], 'expected': 2},
# # ]
# # for t in tests:
# #     test.assert_equals(is_interesting(t['n'], t['interesting']), t['expected'])

import unittest

import re
position = [0, 0]
direction = 0
def i_am_here(path):
    global position
    global direction
    print(path)

    directions = [[-1, 0], [0, 1], [1, 0], [0, -1]]
    m = re.match(r'(^\d+)', path)
    if m:
        position[0] += int(m.groups()[0]) * directions[direction][0]
        position[1] += int(m.groups()[0]) * directions[direction][1]
        path = path[len(m.groups()[0]):]

    for i in re.findall(r'(\w)(\d*)', path):
        if i[0] == 'r':
            direction = (direction + 1) % 4
        elif i[0] == 'l':
            direction = (direction + 3) % 4
        else:
            direction = (direction + 2) % 4

        if i[1]:
            nums = int(i[1])
            position[0] += nums * directions[direction][0]
            position[1] += nums * directions[direction][1]

    print(str(position))
    return position

def where_are_you(path, result):
    assert i_am_here(path) == result, i_am_here(path)

# where_are_you('',       [0, 0])
where_are_you('RLrl',   [0, 0]) # > ^ > ^
where_are_you('r5L2l4', [4, 3]) # > 5 ^ 2 < 4
where_are_you('r5L2l4', [0, 0])
where_are_you('10r5r0', [-10, 5])
where_are_you('10r5r0', [0, 0])
where_are_you('l24l89', [-24, 89])

