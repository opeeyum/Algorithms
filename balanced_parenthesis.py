def ispar(x):
        # code here
        dict_ = {
            '}' : '{',
            ']' : '[',
            ')' : '('
        }
        
        ans = []
        
        for i in x:
            if i == '{':
                ans.append(i)
                print(ans)
            elif i == '[':
                ans.append(i)
                print(ans)
            elif i == '(':
                ans.append(i)
                print(ans)
            elif ans and dict_[i] == ans.pop():
                print(ans)
            else:
                return False
        
        return not bool(ans)

print(ispar('['))