<?php

namespace AlgGraph;

use SplDoublyLinkedList;
use SplFixedArray;

class Utils
{
	static function get_max_degree_mat(SplFixedArray $mat): int
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


	static function get_max_degree_list(array $lists): int
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

	/**
	 * Uses sorted insertion.
	 *
	 * @param array $adj_list Adjacencies list
	 * @return SplDoublyLinkedList Ordered adjacency list
	 */
	static function degree_ordered_adj_list(array $adj_lists): SplDoublyLinkedList
	{

		$list = new SplDoublyLinkedList();

		foreach ($adj_lists as $adj_list) {

			$last = true;
			$list->rewind();
			while ($list->valid()) {

				if ($list->current()->count() >= $adj_list->count()) #insert
				{
					$list->add($list->key(), $adj_list);
					$last = false;
					break;
				}
				$list->next();
			}
			if($last)
				$list->push($adj_list);
		}


		return $list;
	}
}
