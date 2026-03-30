<?php

namespace AlgGraph\Core;
use SplFixedArray;

class GraphGenerator{

    public function random_adj_matrix(int $size, bool $directed = false): SplFixedArray
    {
        $mat = new SplFixedArray($size);

        for ($i = 0; $i < $size; $i++)
            $mat[$i] = SplFixedArray::fromArray(array_fill(0, $size, 0));

        if($directed)
        {
            for ($i = 0; $i < $size; $i++) 
            {
                for ($j = 0; $j < $size; $j++) 
                {
                    if($i==$j) continue;
                    $mat[$i][$j] = (rand() % 2);
                }
            }
        }
        else
        {
            for ($i = 0; $i < ($size - 1); $i++) 
            {
                for ($j = $i + 1; $j < $size; $j++) 
                {
                    $mat[$i][$j] = (rand() % 2);
                    $mat[$j][$i] = $mat[$i][$j];
                }
            }
        }

        return $mat;
    }


    private function create_vertices(SplFixedArray $mat): array{

        $vertices=[];
        for($i=0; $i<$mat->count(); $i++)
            $vertices[] = new Vertex($i);

        return $vertices;
    }

    public function adjmat_to_list(SplFixedArray $mat): array
    {
        $list = [];

        for ($i = 0; $i < $mat->count(); $i++) {
            $list[$i] = [];

            for ($j = 0; $j < $mat->count(); $j++) {
                if ($mat[$i][$j])
                    array_push($list[$i],$j);
            }
        }

        return $list;
    }

    public function get_random_graph(int $size, bool $directed = false) : Graph
    {
        $mat = $this->random_adj_matrix($size,$directed);
        return $this->get_graph($mat,$directed);
    }

    public function get_graph(SplFixedArray|array $adj_matrix, bool $directed): Graph
    {

        $vertices = $this->create_vertices($adj_matrix);
        $adj_list = $this->adjmat_to_list($adj_matrix);

        for($i=0; $i<count($adj_list); $i++)
        {
            for($j=0; $j<count($adj_list[$i]); $j++)
                $vertices[$i]->add_neighbor($vertices[$adj_list[$i][$j]]);
        }

        return new Graph($adj_matrix,$adj_list,$vertices,$directed);
    } 
}


?>