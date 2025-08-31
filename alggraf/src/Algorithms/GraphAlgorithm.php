<?php

namespace AlgGraph\Algorithms;

use AlgGraph\Core\Graph;

abstract class GraphAlgorithm{
	
	protected Graph $graph;

	public function __construct(Graph $graph)
	{
		$this->graph = $graph;
	}

	abstract public function execute();

}