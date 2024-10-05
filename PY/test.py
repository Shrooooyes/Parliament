from chairman import Chairman

chairman = "Hello"

def test():
    globals()['chairman'] += " World!!"
    
test()

print(chairman)