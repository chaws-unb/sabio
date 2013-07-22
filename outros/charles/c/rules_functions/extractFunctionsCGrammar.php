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
	//$newSource = str_replace("();", "()\n{\n\t\n}\n\n", $matches[2][$i]);

	$newFilename = "impl/". strtolower($filename) .".c";

	// Get the source and change void to void *
	$newSource = file_get_contents($newFilename);
	$newSource = str_replace("void *", "void * ", $newSource);
	file_put_contents($newFilename, $newSource);

	// CAUTION: ONLY UNCOMMENT THIS LINE IF, AND ONLY IF, YOU WANT TO DELETE ALL PREVIOUS CODE
	// file_put_contents($neFilename123, $defaultInclude . $newSource);
}

// var_dump($matches);

?>
