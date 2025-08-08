<?php

class Graph
{

    public $adj_matrix;
    public $adj_list;
    public $directed;

    public function __construct(
        SplFixedArray $adj_matrix,
        ?array $adj_list,
        bool $directed = false
    ) {
        $this->adj_matrix = $adj_matrix;
        if (is_array($adj_list))
            $this->adj_list = $adj_list;
        $this->directed = $directed;

    }



    public function print_mat(?SplFixedArray $mat = null)
    {
        $mat = $mat ?? $this->adj_matrix;

        foreach ($mat as $row) {
            foreach ($row as $col) {
                printf(" %d", $col);
            }
            printf("\n");
        }
    }

    public function print_list(?array $lists = null)
    {
        $lists ?? $this->adj_list;

        for ($i = 0; $i < count($lists); $i++) {
            $list_str = "$i";
            for ($lists[$i]->rewind(); $lists[$i]->valid(); $lists[$i]->next()) {
                $list_str .= "->" . $lists[$i]->current();
            }
            echo $list_str . "\n";
        }
    }
}

