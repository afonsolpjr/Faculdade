<?php


use AlgGraph\Core\GraphGenerator;
use AlgGraph\Algorithms\ChromaticNumber;
use PHPUnit\Framework\TestCase;


class ChromaticNumberTest extends TestCase
{
	public function testexecute()
	{
		$gen = new GraphGenerator();
		$graph = $gen->get_graph(SplFixedArray::fromArray([
			[0, 0, 1, 0, 0],
			[0, 0, 1, 0, 0],
			[1, 1, 0, 0, 1],
			[0, 0, 0, 0, 1],
			[0, 0, 1, 1, 0],
		]), false);

		$coloring = new ChromaticNumber($graph);
		$colors = $coloring->execute();

		$this->assertEquals(count($colors), 2);


		for ($i = 3; $i < 100; $i++) {
			$mat = array_fill(0, $i, array_fill(0, $i, 1));

			$graph = $gen->get_graph(SplFixedArray::fromArray($mat), false);
			$coloring = new ChromaticNumber($graph);
			$colors = $coloring->execute();

			$this->assertEquals(count($colors), $i);
		}
	}

	public function testexecute1()
	{
		$gen = new GraphGenerator();
		$graph = $gen->get_graph(SplFixedArray::fromArray([
			[0, 0, 1, 0, 0],
			[0, 0, 1, 0, 0],
			[1, 1, 0, 0, 1],
			[0, 0, 0, 0, 1],
			[0, 0, 1, 1, 0],
		]), false);

		$coloring = new ChromaticNumber($graph);
		$colors = $coloring->execute1();

		$this->assertEquals(2,count($colors));

		for ($i = 3; $i < 100; $i++) {
			$mat = array_fill(0, $i, array_fill(0, $i, 1));

			$graph = $gen->get_graph(SplFixedArray::fromArray($mat), false);
			$coloring = new ChromaticNumber($graph);
			$colors = $coloring->execute1();
			$this->assertEquals($i,count($colors));
		}

	}
}
