<?php
// Définition des variables pour cette page
$pageTitle = "Page d'accueil - Puissance 4 en Profondeur";
$pageDescription = "Découvrez Puissance 4 en Profondeur, une exploration immersive dans les facettes avancées de ce jeu simple mais stratégique.";

// Entête
include 'header.php'; // Assurez-vous que le chemin d'accès est correct
?>

<div class="container" id="contenu">
    <h1 class="mt-4 mb-3">Puissance 4 en Profondeur</h1>
    <section class="my-4">
        <h2>Contexte du Projet</h2>
        <p>En 2022, à l'Université d'Angers, nous avons transformé le jeu classique "Puissance 4"...</p>
    </section>

    <!-- Ajoutez d'autres sections au besoin -->
    <!-- Par exemple, une section sur l'équipe, le développement, etc. -->

    <!-- Inclusion de script JavaScript pour tooltip si nécessaire -->
    <script>
        document.querySelector('#myImage').addEventListener('mousemove', function (e) {
            // Code JavaScript pour le tooltip
        });
        document.querySelector('#myImage').addEventListener('mouseout', function () {
            // Code JavaScript pour le tooltip
        });
    </script>
</div>

<?php
// Pied de page
include 'footer.php'; // Assurez-vous que le chemin d'accès est correct
?>
