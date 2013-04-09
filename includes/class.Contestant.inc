<?php

/**
 * Individual contestant;
 */
class Contestant {
  protected $_name = '';
  protected $_score = 0;

  public function __construct($name, $score = 0) {
    $this->_name = $name;
    $this->_score = (int) $score;
  }

  /**
   * Returns contestant name;
   * @return [type] [description]
   */
  public function getName() {
    return $this->_name;
  }

  /**
   * Returns contestant score.
   * @return [type] [description]
   */
  public function getScore() {
    return $this->_score;
  }

  /**
   * Sets contestant score.
   * @param [type] $score [description]
   */
  public function setScore($score) {
    $this->_score = (int) $score;
  }
}