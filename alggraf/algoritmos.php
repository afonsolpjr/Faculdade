#!/bin/php

<?php 

require 'vendor/autoload.php';

use AlgGraph\Algorithms\AlgorithmFactory;
use AlgGraph\Core\GraphGenerator;
use AlgGraph\Utils;

$generator = new GraphGenerator();
$algs = new AlgorithmFactory;
$mat = [
	[0,1,1,0,0,0,0,0],
	[0,1,0,1,0,0,0,0],
	[0,0,0,0,1,1,0,0],
	[0,0,0,0,0,0,1,1],
	[0,0,1,0,0,0,0,0],
	[0,0,1,0,0,0,0,0],
	[0,0,0,1,0,0,0,0],
	[0,0,0,1,0,0,0,0]
];

$graph = $generator->get_graph(SplFixedArray::fromArray($mat),false);

echo $algs->chromatic_number($graph);

?>