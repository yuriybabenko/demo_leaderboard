<?php

/**
 * Core data class to be extended by Data Type classes (Session, Database, etc.)
 */
abstract class Data {
  /**
   * Returns a hash for the contestant's name.
   * @param  [type] $name [description]
   * @return [type]       [description]
   */
  public function contestantKey($name) {
    // can't have two contestants with identical names
    return md5($name . 'bbtv');
  }
}