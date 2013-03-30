<?php

function module_taxonomy_term_page($term) {
  // для динамической работы будем анализировать из какого словаря термин
  switch($term->vocabulary_machine_name) {
    case 'category': {
			
			$terms = taxonomy_get_children($term->tid, $term->vid);
			
			if ($terms) {
				$items = array();
				foreach ($terms as $term) {
				  $items[] = l($term->name, 'taxonomy/term/' . $term->tid);
				}
				$output = theme('subtaxonomy_list', $items);
	      return $output;
			}
			else {
	      module_load_include('inc', 'taxonomy', 'taxonomy.pages');
	      return taxonomy_term_page($term);
			}
      break;
    }
    default: {
      // Стандартная страница таксономии для остальных словарей таксономии
      module_load_include('inc', 'taxonomy', 'taxonomy.pages');
      return taxonomy_term_page($term);
    }
  }
}