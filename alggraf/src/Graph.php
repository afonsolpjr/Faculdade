<?php

namespace AlgGraph;
use SplFixedArray;

class Graph
{

    public $adj_matrix;
    public $adj_list;
    public $directed;
    public $degrees;
    public $n;
    public $m;

    public function __construct(
        SplFixedArray $adj_matrix,
        ?array $adj_list,
        bool $directed = false
    ) {
        $this->adj_matrix = $adj_matrix;
        if (is_array($adj_list))
            $this->adj_list = $adj_list;
        
        $this->directed = $directed;
        $this->n = count($adj_matrix);
        $this->count_edges();


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
        
        if($this->directed)
            return;

        $adj_matrix[$v2][$v1] = 1;
        $this->adj_list[$v2]->push($v1);
    }

    public function remove_edge($v1, $v2): void
    {
        $this->adj_matrix[$v1][$v2] = 0;
        
        $list = $this->adj_list[$v1];
        $list->rewind();
        while($list->valid())
        {
            if( $list->current() == $v2 )
                $list->offsetUnset($list->key());
            $list->next();
        }

        
        if($this->directed)
            return;

        $this->adj_matrix[$v2][$v1] = 0;
        $list = $this->adj_list[$v2];
        $list->rewind();
        while($list->valid())
        {
            if( $list->current() == $v2 )
                $list->offsetUnset($list->key());
            $list->next();
        }
    }

    public function test_adj($v1,$v2): bool
    {
        return $this->adj_matrix[$v1][$v2];
    }

    private function count_edges(): void
    {
        $this->m=0;
        foreach($this->adj_list as $list)
            $this->m += $list->count();
    }

    public function nodes()
    {
        for($i=0; $i<$this->n; $i++)
            yield $i;
    }
}

