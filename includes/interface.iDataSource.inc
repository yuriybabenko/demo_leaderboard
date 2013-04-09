<?php

/**
 * Common interface for data sources.
 */
interface iDataSource {
  public function set($name, $value);
  public function get($name);
  public function wipe();
}