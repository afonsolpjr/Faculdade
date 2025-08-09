<?php

use AlgGraph\GraphGenerator;
use AlgGraph\Utils;
use PHPUnit\Framework\TestCase;


class UtilsTest extends TestCase
{
	public function testListOrdering()
	{
		$graph_generator = new GraphGenerator();
		$graph = $graph_generator->get_random_graph(7);

		$ordered_list = Utils::degree_ordered_adj_list($graph->adj_list);
		print_r($graph->adj_list);
		print_r($ordered_list);

		$ordered = true;
		
		if ($ordered_list->count() != count($graph->adj_list))
			$ordered = false;

		for ($i=0; $i < count($ordered_list) - 1 ; $i++) { 
			if($ordered_list[$i] > $ordered_list[$i+1])
				$ordered = false;
		}
		
		$this->assertEquals($ordered,true);
	}
}


?>