<?php

function print_rr($data) {
  if ($_SERVER['REMOTE_ADDR'] !== '127.0.0.1') {
    return;
  }

  echo '<pre style="border: 1px #333 solid; margin: 10px; padding: 10px; font-size: 16px; color: #333;">';
  print_r($data);
  echo '</pre>';
}