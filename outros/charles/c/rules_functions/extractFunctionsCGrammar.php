<?php 

$source = file_get_contents("temp_cGrammar.h");

preg_match_all('%//\s*([\w_]+)\s(.*?)___%mis', $source, $matches);

$defaultInclude = "#include <stdio.h>\n";
$defaultInclude .= "#include <stdlib.h>\n";
$defaultInclude .= "#include <string.h>\n";
$defaultInclude .= "#include \"../cGrammar.h\"\n";
$defaultInclude .= "\n\n";

foreach($matches[1] as $i => $filename)
{
	// Replace (); to {}
	$newSource = str_replace("();", "()\n{\n\t\n}\n\n", $matches[2][$i]);
	file_put_contents("impl/". strtolower($filename) .".c", $defaultInclude . $newSource);
}

// var_dump($matches);

?>
