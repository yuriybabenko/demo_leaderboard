<?php

interface iDataSource {
  public function set($name, $value);
  public function get($name);
  public function all();
  public function wipe();
}