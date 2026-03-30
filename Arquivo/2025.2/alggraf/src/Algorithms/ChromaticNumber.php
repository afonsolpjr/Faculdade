<?php


namespace AlgGraph\Algorithms;
use AlgGraph\Core\Vertex;

/**
 * Calculates approximated chromatic number.
 */
class ChromaticNumber extends GraphAlgorithm{

	//$this->graph;
	
	public function execute()
	{
		/** WHat i want: list of vertex sorted by degree, descending */

		$vertices = $this->graph->vertices;

		usort($vertices,function (Vertex $v1, Vertex $v2){
			/**
			 * usort:
			 * if arg1 should be after arg2, return >0
			 */
			return $v2->degree <=> $v1->degree;
		});



		$colors=[[$vertices[0]]];

		for($i=1;$i<count($vertices); $i++)
		{
			for($j=0;$j<count($colors); $j++)
			{
				//check neighbors
				$has_colored_neighbor = false;

				foreach ($vertices[$i]->neighbors as $neighbor) {
					if(in_array($neighbor,$colors[$j]))
					{
						$has_colored_neighbor = true;
						break;
					}
				}

				if(! $has_colored_neighbor)
				{
					$colors[$j][] = $vertices[$i];
					break;
				}
			}

			if($j==count($colors))
			{
				$colors[] = [$vertices[$i]];
			}

		}
		return $colors;

	}


	public function execute1()
	{
		/** WHat i want: list of vertex sorted by degree, descending */

		$vertices = $this->graph->vertices;

		usort($vertices,function (Vertex $v1, Vertex $v2){
			/**
			 * usort:
			 * if arg1 should be after arg2, return >0
			 */
			return $v2->degree <=> $v1->degree;
		});

		foreach ($vertices as $vertex) {
			$vertex->color=-1;
		}

		$vertices[0]->color = 0;

		for($i=1;$i<count($vertices); $i++)
		{
			$available_colors = array_fill(0,count($vertices),1);
			
			foreach ($vertices[$i]->neighbors as $neighbor)
			{
				if($neighbor->color != -1)
					$available_colors[$neighbor->color] = 0;
			}

			for($j=0;$j<count($vertices);$j++)
			{
				if($available_colors[$j]){
					$vertices[$i]->color = $j;
					break;
				}
			}

		}
		$colors = [];

		foreach($vertices as $vertex)
		{
			if(!isset($colors[$vertex->color]))
				$colors[$vertex->color] = [];
			
			$colors[$vertex->color][] = $vertex;
			
		}

		return $colors;

	}
}