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



@app.route('/register', methods=['GET'])
def register_get():
    return render_template("form.html", error="")

@app.route('/register', methods=['POST'])
def register_post():
    if controller.create_user() == True:
        return redirect('signin')
    else:
        return render_template("form.html", error="Username already taken")



@app.route('/signin', methods=['GET'])
def signin_get():
    return render_template("login.html", error="")

@app.route('/signin', methods=['POST'])
def signin_post():
    if controller.connect() == True:
        return redirect('create')
    else:
        return render_template("login.html", error="username or password failed")



@app.route('/signout', methods=['GET', 'POST'])
def signout():
    session.pop('username', None)
    return redirect('index')



@app.route('/create', methods=['GET'])
def create_get():
    return render_template("create.html", user = session['username'])

@app.route('/create', methods=['POST'])
def create():
    if controller.create_task() == True:
        return render_template("create.html", user = session['username'])
    else:
        return render_template("create.html", user = session['username'], error="Fill All !")



""" @app.route('/user', methods=['GET', 'POST'])
def route_add_user():
    username = session['username']
    uid = cursor.execute("SELECT user_id FROM user WHERE username = (%s)", username)
    uid = cursor.fetchone()[0]
    return render_template("create.html", user = username) """