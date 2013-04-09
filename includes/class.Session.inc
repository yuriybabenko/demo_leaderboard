<?php

/**
 * Session data source handling.
 */
class Session extends Data implements iDataSource {
  protected $_contestants = array();

  public function __construct($contestants) {
    session_start();

    // pull up existing contestant data from session
    if ($existing = $this->get('contestants')) {
      $this->_contestants = $existing;
    }
    // otherwise instantiate the contestants
    else {
      foreach ($contestants as $name => $score) {
        $key = $this->contestantKey($name);

        $this->_contestants[$key] = new Contestant($name, $score);
      }

      $this->set('contestants', $this->_contestants);
    }
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

    return FALSE;
  }

  /**
   * Returns all contestants.
   * @return [type] [description]
   */
  public function getContestants() {
    return $this->_contestants;
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