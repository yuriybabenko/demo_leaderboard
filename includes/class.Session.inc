<?php

class Session implements iDataSource {
  public function __construct() {
    session_start();
  }

  /**
   * Sets value for specified variable name.
   * @param [type] $name  [description]
   * @param [type] $value [description]
   */
  public function set($name, $value) {
    $_SESSION[$name] = $value;
  }

  /**
   * Gets value for specified variable name.
   * @param  [type] $name [description]
   * @return [type]       [description]
   */
  public function get($name) {
    if (isset($_SESSION[$name])) {
      return $_SESSION[$name];
    }
  }
  
  /**
   * Returns all stored data.
   * @return [type] [description]
   */
  public function all() {
    return $_SESSION;
  }

  /**
   * Erases all stored data.
   * @return [type] [description]
   */
  public function wipe() {
    session_destroy();
    $_SESSION = array();
  }
}