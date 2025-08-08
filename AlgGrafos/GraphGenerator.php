<?php


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

    public function adjmat_to_list(SplFixedArray $mat): array
    {
        $list = [];

        for ($i = 0; $i < $mat->count(); $i++) {
            array_push($list, new SplDoublyLinkedList());

            for ($j = 0; $j < $mat->count(); $j++) {
                if ($mat[$i][$j])
                    $list[$i]->push($j);
            }
        }

        return $list;
    }

    public function get_random_graph(int $size, bool $directed = false) : Graph
    {
        $mat = $this->random_adj_matrix($size,$directed);
        return new Graph($mat,$this->adjmat_to_list($mat),$directed);
    }
}


?>