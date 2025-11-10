m = 8
n = 5
l = 1
t = 100

m = 8
n = 8
l = 0
t = 100007


columns = m-1

# ((((7 * (7+1)) // 2) - ((1 * (1+1)) // 2) - (1*(7-((1 * (1+1)) // 2)))) * 5) % 100
#   ^                    ^                    ^                             ^    ^
#   | Sum of ro w        |                    |                             |    |
#                        |                    |                             |    |
#                        | Number of elements lower than loss               |    |
#                                             | Subtract loss               |    |
#                                                           Number of rows >|    |
#                                                                 Counter size > |
# ((((8 * (8+1)) // 2) - ((0 * (0+1)) // 2) - (1*(8-((0 * (0+1)) // 2)))) * 8) % 100007
print(((((columns * (columns+1)) // 2) - ((l * (l+1)) // 2) - (1*(columns-((l * (l+1)) // 2)))) * n) % t)
