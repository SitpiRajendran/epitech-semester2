from app import app, models
from flask import *
from werkzeug.security import generate_password_hash, check_password_hash
from pymysql import cursors

#########################       user      #########################

def create_user():
    ID = request.form['username']
    PWD = generate_password_hash(request.form['password'])
    if models.user_id_exist(ID) == True:
        return False
    models.add_user(ID, PWD)
    return True

def connect():
    USER = request.form['username']
    PASS = request.form['password']
    if models.verifypwd(USER, PASS) == True:
        session['username'] = USER
        return True
    else:
        return False

def create_user_json():
    content = request.get_json()
    ID = content['username']
    PWD = generate_password_hash(content['password'])
    if models.user_id_exist(ID) == True:
        return False
    models.add_user(ID, PWD)
    return True

def connect_json():
    content = request.get_json()
    USER = content['username']
    PASS = content['password']
    if models.verifypwd(USER, PASS) == True:
        session['username'] = USER
        return True
    else:
        return False

#########################      task      #########################

def create_task():
    if 'username' in session:
        TITLE = request.form['title']
        BEGIN = request.form['begin']
        END = request.form['end']
        STATUS = request.form['status']
        if BEGIN == "" or END == "" or TITLE == "":
            return False
        models.add_task(TITLE, BEGIN, END, STATUS)
        return True
    else :
        return False










