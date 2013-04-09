<?php
  define('POINTS_VALUE',  5);
  define('BASE_PATH',     'http://bbtv/');

  require_once('./includes/debug.inc');
  require_once('./includes/interface.iDataSource.inc');
  require_once('./includes/class.Contestant.inc');
  require_once('./includes/class.Data.inc');
  require_once('./includes/class.Session.inc');
  
  // available contestants & default scores
  $contestants = array(
    'Marie Curie' => 0,
    'Claude Shannon' => 0,
    'Ada Lovelace' => 0,
    'Nikola Tesla' => 0,
    'Carl Friedrich Gauss' => 0,
    'Grace Hopper' => 0,
  );

  $data = new Session($contestants);

  // handle AJAX request to give a contestant points
  if (isset($_GET['target'])) {
    if ($existing = $data->getContestants()) {
      if (isset($existing[$_GET['target']])) {
        // at this point $contestant holds a copy of the identifier pointing to the 
        // original object in session, so simply updating the object will update the
        // session data
        $contestant = $existing[$_GET['target']];

        $score = $contestant->getScore();
        $contestant->setScore($score + POINTS_VALUE);

        // print out the new score so it can be sent back in the response
        echo $contestant->getScore();
      }
    }
    exit();
  }
?>

<!DOCTYPE html>
<html>
<head>
  <title>Leaderboard</title>

  <link rel="stylesheet" href="<?php echo BASE_PATH; ?>css/style.css">

  <script type="text/javascript" src="<?php echo BASE_PATH; ?>js/jquery-1.9.1.min.js"></script>
  <script type="text/javascript" src="<?php echo BASE_PATH; ?>js/bbtv.js"></script>
</head>
<body>
  <div id="outer">
    <div class="leaderboard">
      <?php
        foreach ($data->getContestants() as $key => $contestant) {
          echo '
                  <div class="contestant" id="' . $key . '">
                    <span class="name">' . $contestant->getName() . '</span>
                    <span class="score">' . $contestant->getScore() . '</span>
                  </div>
               ';
        }
      ?>
    </div>
    <div class="none">
      Click a player to select
    </div>
    <div class="details">
      <div class="name"></div>
      <input type="button" class="inc" value="Give <?php echo POINTS_VALUE; ?> points">
    </div>
  </div>
</body>
</html>
