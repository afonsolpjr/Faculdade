<?php

namespace AlgGraph\Algorithms;

use AlgGraph\Core\Graph;

class AlgorithmFactory{
	
	public function chromatic_number(Graph $graph)
	{
		$alg = new ChromaticNumber($graph);
		$colors = $alg->execute();

		return $colors;
	}

}