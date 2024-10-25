def MathChallenge(strParam):
    operators=["+","-","*","/"]
    for i in range(len(strParam)):
        if(i+1<len(strParam) and strParam[i]==")" and (strParam[i+1] not in operators)):
            strParam=strParam[:i+1]+"*"+strParam[i+1:]
        elif(i-1>=0 and strParam[i]=="(" and (strParam[i-1] not in operators)):
            strParam=strParam[:i]+"*"+strParam[i:]
    strParam=str(int(eval(strParam)))
    return strParam

print(MathChallenge(input()))