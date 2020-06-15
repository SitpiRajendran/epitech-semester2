from app import app
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
    ID = cursor.execute("SELECT user_id FROM user WHERE username = (%s)", username)
    ID = cursor.fetchone()[0]
    return(ID)

def add_task(TITLE, BEGIN, END, STATUS):
    ID = get_user_id()
    sql = "INSERT INTO task(title,begin,end,status) VALUES(%s,%s,%s,%s)"
    cursor.execute(sql, (TITLE,BEGIN,END,STATUS))
    db.commit()
    TASKID = cursor.execute("SELECT * FROM task WHERE title = (%s)", TITLE)
    TASKID = cursor.fetchone()[0]
    cursor.execute("INSERT INTO user_has_task(fk_user_id,fk_task_id) VALUES(%s,%s)", (ID,TASKID))
    db.commit()
