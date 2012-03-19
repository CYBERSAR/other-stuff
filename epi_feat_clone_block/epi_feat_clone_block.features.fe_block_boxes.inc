<?php

/**
 * Implementation of hook_default_fe_block_boxes().
 */
function epi_feat_clone_block_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'Consente di clonare un oggetto fedora';
  $fe_block_boxes->format = '3';
  $fe_block_boxes->machine_name = 'clone_fedora_object_block';
  $fe_block_boxes->body = '<?php
    $object_pid_full = arg(2);

    if ( arg(0) == "fedora" && arg(1) == "repository" &&  !empty($object_pid_full) ) {
    	module_load_include(\'module\', \'islandora_mag\', \'islandora_mag\');
    	$coll = getAllInfoCollectionPid($object_pid_full);
    	$exploded_pid = explode(":", $object_pid_full);
    	$pid = $exploded_pid[1];

    	if ( is_numeric($pid) ) {
    		$path = drupal_get_path(\'module\', \'islandora_mag\');
    		global $base_url;

    		echo \'<a title="\' . t(\'Create a New object like that\') . \'"  href="\' . base_path() .  \'fedora/cloneObject/\' . $coll[\'uri\'] . "/" . $coll[\'title\'] . "/-/" .  $object_pid_full  . \'">\';
    		echo \'<img src="\' . $base_url . \'/\' . $path .  \'/images/clone.png" alt="\' . t(\'Create a New Object like that\') . \'" class="icon">\';
    		echo \'</a>\' . t(\'Clone it!\');
    	}
    }

?>';

  $export['clone_fedora_object_block'] = $fe_block_boxes;

  return $export;
}
