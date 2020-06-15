from app import app, models
from flask import *
from werkzeug.security import generate_password_hash, check_password_hash
from pymysql import cursors

#########################       user      #########################

def create_user():
    content = request.get_json()
    ID = content['username']
    PWD = generate_password_hash(content['password'])
    if models.user_id_exist(ID) == True:
        return False
    models.add_user(ID, PWD)
    return True

def connect():
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
    content = request.get_json()
    TITLE = content['title']
    BEGIN = content['begin']
    END = content['end']
    STATUS = content['status']
    if BEGIN == "" or END == "" or TITLE == "":
        return False
    if not (STATUS == "done" or STATUS == "not started" or STATUS == "in progress"):
        return False
    models.add_task(TITLE, BEGIN, END, STATUS)
    return True

def task_exist(id):
    if models.task_ex(id) == 1:
        return True
    else:
        return False

def modif_task(id):
    content = request.get_json()
    TITLE = content['title']
    BEGIN = content['begin']
    END = content['end']
    STATUS = content['status']
    models.modify_task(TITLE, BEGIN, END, STATUS, id)
    return True









