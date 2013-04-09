<?php
  $base_path = 'http://bbtv/';

  require_once('./includes/debug.inc');
  require_once('./includes/interface.iDataSource.inc');
  require_once('./includes/class.Session.inc');
  
  $data = new Session();
?>

<!DOCTYPE html>
<html>
<head>
  <title>Leaderboard</title>

  <link rel="stylesheet" href="<?php echo $base_path; ?>css/style.css">

  <script type="text/javascript" src="<?php echo $base_path; ?>js/jquery-1.9.1.min.js"></script>
  <script type="text/javascript" src="<?php echo $base_path; ?>js/bbtv.js"></script>
</head>
<body>
  <div id="outer">
    <div class="leaderboard">
      <div class="player">
        <span class="name">Marie Curie</span>
        <span class="score">123</span>
      </div>
    </div>
    <div class="none">
      Click a player to select
    </div>
    <div class="details">
      <div class="name">John Smith</span>
      <input type="button" class="inc" value="Give 5 points">
    </div>
  </div>
</body>
</html>
