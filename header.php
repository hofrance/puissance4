<!DOCTYPE html>
<html lang="fr">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="<?php echo $pageDescription; ?>">
    <title><?php echo $pageTitle; ?></title>
    <!-- Bootstrap CSS et autres dépendances -->
    <link rel="stylesheet" href="css/style.css">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.16.0/umd/popper.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js"></script>

    <?php
    // Autres éléments spécifiques à chaque page, comme des styles ou des scripts supplémentaires
    if (isset($additionalHeadContent)) {
        echo $additionalHeadContent;
    }
    ?>
</head>

<body>
    <div id="contenu" class="container">
        <header class="mb-4">
            <nav class="navbar navbar-expand-lg navbar-light bg-light">
                <a class="navbar-brand" href="#">Puissance 4</a>
                <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarNav" aria-controls="navbarNav" aria-expanded="false" aria-label="Toggle navigation">
                    <span class="navbar-toggler-icon"></span>
                </button>
                <div class="collapse navbar-collapse" id="navbarNav">
                    <ul class="navbar-nav ml-auto">
                        <li class="nav-item">
                            <a class="nav-link" href="./presentationDuJeu.php">Présentation du jeu</a>
                        </li>
                        <li class="nav-item">
                            <a class="nav-link" href="./algorithmeDuJeu.php">Algorithme du jeu</a>
                        </li>
                        <li class="nav-item">
                            <a class="nav-link" href="./presentationIa.php">Intelligence artificielle du jeu</a>
                        </li>
                        <li class="nav-item">
                            <a class="nav-link" href="./presentationDuGroupe.php">Présentation du groupe</a>
                        </li>
                    </ul>
                </div>
            </nav>
        </header>
        <!-- Reste du contenu spécifique à chaque page -->
    </div>
</body>
</html>
