from app import app, views, controller
from config import *
import pymysql as sql
from flask import Flask, render_template, jsonify, request, redirect, session
from werkzeug.security import generate_password_hash, check_password_hash
from pymysql import cursors

db = sql.connect(host=DATABASE_HOST, user=DATABASE_USER, db=DATABASE_NAME)
cursor = db.cursor()

def user_id_exist(user):
    x = cursor.execute("SELECT * FROM user WHERE username = (%s)", user)
    if int(x) > 0:
        return True
    else:
        return False

def add_user(user, pwd):
    sql = "INSERT INTO user(username,password) VALUES(%s,%s)"
    cursor.execute(sql, (user,pwd))
    db.commit()

def verifypwd(user, pwd):
    x = cursor.execute("SELECT * FROM user WHERE username = (%s)", user)
    if int(x) == 1:
        x = cursor.execute("SELECT * FROM user WHERE username = (%s)", user)
        x = cursor.fetchone()[2]
        if check_password_hash(x, pwd) == True:
            return True
    return False

def get_user_id():
    username = session['username']
    ID = cursor.execute("SELECT * FROM user WHERE username = (%s)", username)
    ID = cursor.fetchone()[0]
    return(ID)

def get_user_name():
    username = session['username']
    ID = cursor.execute("SELECT * FROM user WHERE username = (%s)", username)
    ID = cursor.fetchone()[1]
    return(ID)

def get_user_pwd():
    username = session['username']
    ID = cursor.execute("SELECT * FROM user WHERE username = (%s)", username)
    ID = cursor.fetchone()[2]
    return(ID)

def get_user_data():
    username = session['username']
    cursor.execute("SELECT * FROM user WHERE username = (%s)", username)
    result = cursor.fetchall()
    return (result)

def add_task(TITLE, BEGIN, END, STATUS):
    ID = get_user_id()
    sql = "INSERT INTO task(title,begin,end,status) VALUES(%s,%s,%s,%s)"
    cursor.execute(sql, (TITLE,BEGIN,END,STATUS))
    db.commit()
    TASKID = cursor.execute("SELECT * FROM task WHERE title = (%s)", TITLE)
    TASKID = cursor.fetchone()[0]
    cursor.execute("INSERT INTO user_has_task(fk_user_id,fk_task_id) VALUES(%s,%s)", (ID,TASKID))
    db.commit()

def get_task_name(id):
    cursor.execute("SELECT * FROM task WHERE task_id = (%s)", id)
    ID = cursor.fetchone()[1]
    return(ID)

def get_task_begin(id):
    cursor.execute("SELECT * FROM task WHERE task_id = (%s)", id)
    ID = cursor.fetchone()[2]
    return(ID)

def get_task_end(id):
    cursor.execute("SELECT * FROM task WHERE task_id = (%s)", id)
    ID = cursor.fetchone()[3]
    return(ID)

def get_task_status(id):
    cursor.execute("SELECT * FROM task WHERE task_id = (%s)", id)
    ID = cursor.fetchone()[4]
    return(ID)

def task_ex(id):
    return (cursor.execute("SELECT * FROM task WHERE task_id = (%s)", id))

def modify_task(TITLE, BEGIN, END, STATUS, id):
    sql = "UPDATE user SET title = (%s),begin = (%s),end = (%s), status = (%s) WHERE id = (%s)"
    cursor.execute(sql, (TITLE),(BEGIN),(END),(STATUS), (id))
