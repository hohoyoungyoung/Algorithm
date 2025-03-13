def solution(id_pw, db):
    
    dictionary = dict(db)
    id, pw = id_pw[0], id_pw[1]
    
    for i in dictionary:
        if (i == id) and (pw == dictionary[i]):
            return 'login'
        if (i == id) and (pw != dictionary[i]):
            return 'wrong pw'
        
    return 'fail' 