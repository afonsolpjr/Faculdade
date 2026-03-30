<?php

namespace AlgGraph;

use SplDoublyLinkedList;
use SplFixedArray;

class Utils
{
	private function get_max_degree_mat(SplFixedArray $mat): int
	{

		$max = 0;
		foreach ($mat as $line) {
			$current_degree = 0;

			foreach ($line as $adj)
				$current_degree += $adj;

			$max = $current_degree > $max ? $current_degree : $max;
		}

		return $max;
	}


	private function get_max_degree_list(array $lists): int
	{
		$max = 0;

		foreach ($lists as $list) {
			$current_degree = 0;
			for ($list->rewind(); $list->valid(); $list->next())
				$current_degree++;

			$max = $current_degree > $max ? $current_degree : $max;
		}
		return $max;
	}


}
