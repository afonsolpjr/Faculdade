<?php

namespace AlgGraph\Core;
use SplFixedArray;
use Vertex;

class Graph
{

    public $adj_matrix;
    public $adj_list;
    public $directed;
    public $degrees;
    public $n;
    public $m;

    public array $vertices;

    public function __construct(
        SplFixedArray $adj_matrix,
        ?array $adj_list,
        array $vertices,
        bool $directed = false
    ) {
        $this->adj_matrix = $adj_matrix;
        if (is_array($adj_list))
            $this->adj_list = $adj_list;
        
        $this->directed = $directed;
        $this->n = count($adj_matrix);
        $this->count_edges();
        $this->vertices = $vertices;
    }



    public function print_mat(?SplFixedArray $mat = null): void
    {
        $mat = $mat ?? $this->adj_matrix;

        foreach ($mat as $row) {
            foreach ($row as $col) {
                printf(" %d", $col);
            }
            printf("\n");
        }
    }

    public function print_list(?array $lists = null): void
    {
        $lists = $lists ?? $this->adj_list;

        for ($i = 0; $i < count($lists); $i++) {
            $list_str = "$i";
            for ($lists[$i]->rewind(); $lists[$i]->valid(); $lists[$i]->next()) {
                $list_str .= "->" . $lists[$i]->current();
            }
            echo $list_str . "\n";
        }
    }

    public function add_edge($v1, $v2): void
    {
        $adj_matrix[$v1][$v2] = 1;
        $this->adj_list[$v1]->push($v2);

        $this->vertices[$v1]->add_neighbor($this->vertices[$v2]);
        if($this->directed)
            return;

        $this->vertices[$v2]->add_neighbor($this->vertices[$v1]);
        $adj_matrix[$v2][$v1] = 1;
        $this->adj_list[$v2]->push($v1);
    }

    public function remove_edge($v1, $v2): void
    {
        $this->adj_matrix[$v1][$v2] = 0;
        
        $key = array_search($v2,$this->adj_list[$v1]);

        if($key !== false)
            unset($this->adj_list[$v1][$key]);
        
        $this->adj_list[$v1] = array_values($this->adj_list[$v1]);
        
        if($this->directed)
            return;

        $this->adj_matrix[$v2][$v1] = 0;
        $key = array_search($v1,$this->adj_list[$v2]);

        if($key !== false)
            unset($this->adj_list[$v2][$key]);
        
        $this->adj_list[$v2] = array_values($this->adj_list[$v2]);
        
    }

    public function test_adj($v1,$v2): bool
    {
        return $this->adj_matrix[$v1][$v2];
    }

    private function count_edges(): void
    {
        $this->m=0;
        foreach($this->adj_list as $list)
            $this->m += count($list);
    }

    public function nodes()
    {
        for($i=0; $i<$this->n; $i++)
            yield $i;
    }
}

