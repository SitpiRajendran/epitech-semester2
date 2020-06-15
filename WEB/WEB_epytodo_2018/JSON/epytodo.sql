CREATE DATABASE IF NOT EXISTS epytodo;
USE epytodo;

CREATE TABLE IF NOT EXISTS user (
  user_id int(11) NOT NULL AUTO_INCREMENT,
  username varchar(50) NOT NULL,
  password varchar(100) NOT NULL,
  PRIMARY KEY (user_id),
  UNIQUE KEY username (username)
);

CREATE TABLE IF NOT EXISTS task (
  task_id int(11) NOT NULL AUTO_INCREMENT,
  title varchar(50) NOT NULL,
  begin datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  end datetime DEFAULT NULL,
  status enum('not started','in progress','done') NOT NULL DEFAULT 'not started',
  PRIMARY KEY (task_id)
);

CREATE TABLE IF NOT EXISTS user_has_task (
  id int(11) NOT NULL AUTO_INCREMENT,
  fk_user_id int(11) NOT NULL,
  fk_task_id int(11) NOT NULL,
  PRIMARY KEY (id),
  KEY fk_user_id (fk_user_id),
  KEY fk_task_id (fk_task_id)
);