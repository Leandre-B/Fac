<!DOCTYPE html>
<html>
<head>
<title>Téléversement de fichier</title>
</head>
<body>
	<form action="<?= $_SERVER['PHP_SELF'] ?>" method="post"
		enctype="multipart/form-data">
		<fieldset>
			<legend>
				<b>Transférez un fichier ZIP</b>
			</legend>
			<table border="1">
				<tr>
					<td>Choisissez un fichier</td>
					<td><input type="file" name="fich" accept="application/zip" /></td>
					<td><input type="hidden" name="MAX_FILE_SIZE" value="1000000" /></td>
				</tr>
				<tr>
					<td>&nbsp;</td>
					<td><input type="submit" value="ENVOI" /></td>
				</tr>
			</table>
		</fieldset>
	</form>
</body>
</html>
<?php
// A COMPLETER
?>