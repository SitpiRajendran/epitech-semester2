import pymysql as sql
from app import app, controller, models
from flask import Flask, render_template, jsonify, request, redirect, session
from werkzeug.security import generate_password_hash, check_password_hash
from pymysql import cursors

app.secret_key = 'ae*ù85cv:!juv4/v[fd'

@app.route('/', methods=['GET'])
@app.route('/index', methods=['GET'])
def route_home():
    return render_template("index.html")

@app.route('/register', methods=['POST'])
def register_post():
    if controller.create_user() == True:
        return jsonify(result="account created")
    else:
        return jsonify(error="account already exists")

@app.route('/signin', methods=['POST'])
def signin_post():
    if controller.connect() == True:
        return jsonify(result="signin successful")
    else:
        return jsonify(error="login or password does not match")



@app.route('/signout', methods=['GET', 'POST'])
def signout():
    session.pop('username', None)
    return jsonify(result="signout successful")

@app.route('/user', methods=['GET'])
def usershow():
    if 'username' in session:
        name = models.get_user_name()
        pwd = models.get_user_pwd()
        return jsonify(result={'username' : name, 'password' : pwd})
    else :
        return jsonify(error="you must be logged in")


@app.route('/user/task', methods=['GET'])
def showtasks():
    return jsonify(error="you must be logged in")

@app.route('/user/task/<id>', methods=['GET'])
def showonetask(id):
    if 'username' in session:
        if controller.task_exist(id):
            name = models.get_task_name(id)
            begin = models.get_task_begin(id)
            end = models.get_task_end(id)
            status = models.get_task_status(id)
            return jsonify(result={'title' : name, 'begin' : begin, 'end' : end, 'status' : status})
        else:
            return jsonify(error="task id does not exist")
    else:
        return jsonify(error="you must be logged in")

@app.route('/user/task/<id>', methods=['POST'])
def modonetask(id):
    if 'username' in session:
        if controller.task_exist(id):
            content = request.get_json()
            TITLE = content['title']
            BEGIN = content['begin']
            END = content['end']
            STATUS = content['status']
            if BEGIN == "" or END == "" or TITLE == "":
                return jsonify(error="internal error")
            if not (STATUS == "done" or STATUS == "not started" or STATUS == "in progress"):
                return jsonify(error="internal error")
            return jsonify(result="update done")
        else:
            return jsonify(error="task id does not exist")
    else:
        return jsonify(error="you must be logged in")

@app.route('/user/task/add', methods=['POST'])
def add_task():
    if 'username' in session:
        content = request.get_json()
        TITLE = content["title"]
        BEGIN = content['begin']
        END = content['end']
        STATUS = content['status']
        if BEGIN == "" or END == "" or TITLE == "":
            return jsonify(error="internal error")
        if not (STATUS == "done" or STATUS == "not started" or STATUS == "in progress"):
            return jsonify(error="internal error")
        models.add_task(TITLE, BEGIN, END, STATUS)
        return jsonify(result="new task added")
    else:
        return jsonify(error="you must be logged in")

@app.route('/user/task/del/<id>', methods=['POST'])
def delete_task():
    if 'username' in session:
        if controller.task_exist(id):
            return jsonify(result="task deleted")
        else:
            return jsonify(error="task id does not exist")
    else:
        return jsonify(error="you must be logged in")
