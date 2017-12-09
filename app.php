<?php

# [START all]
use Silex\Application;
use Silex\Provider\TwigServiceProvider;
use Symfony\Component\HttpFoundation\Request;
// create the Silex application
$app = new Application();
$app->register(new TwigServiceProvider());
$app['twig.path'] = [ __DIR__ ];
$app->get('/', function () use ($app) {
    /** @var PDO $db */
    $db = $app['database'];
    /** @var Twig_Environment $twig */
    $twig = $app['twig'];
    // Show existing employer entries.
    $results = $db->query('SELECT * from employers');
    return $twig->render('cloudsql.html.twig', [
        'results' => $results,
    ]);
});
$app->post('/', function (Request $request) use ($app) {
    /** @var PDO $db */
    $db = $app['database'];
    $name = $request->request->get('name');
    $content = $request->request->get('content');
    if ($name && $content) {
        $stmt = $db->prepare('INSERT INTO employers (firstname, lastname, company, email, phone, website, referred, details) VALUES (:firstname, :lastname, :company, :email, :phone, :website, :referred, :details)');
        $stmt->execute([
            ':firstname' => $firstname,
            ':lastname' => $lastname,
            ':company' => $company,
            ':email' => $email,
            ':phone' => $phone,
            ':website' => $website,
            ':referred' => $referred,
            ':details' => $details
        ]);
    }
    return $app->redirect('/');
});
// function to return the PDO instance
$app['database'] = function () use ($app) {
    // Connect to CloudSQL from App Engine.
    $dsn = getenv('MYSQL_DSN');
    $user = getenv('MYSQL_USER');
    $password = getenv('MYSQL_PASSWORD');
    if (!isset($dsn, $user) || false === $password) {
        throw new Exception('Set MYSQL_DSN, MYSQL_USER, and MYSQL_PASSWORD environment variables');
    }
    $db = new PDO($dsn, $user, $password);
    return $db;
};
# [END all]
$app->get('create_tables', function () use ($app) {
    /** @var PDO $db */
    $db = $app['database'];
    # [START create_tables]
    // create the tables
    $stmt = $db->prepare('CREATE TABLE IF NOT EXISTS employers ('
        . 'entryID INT NOT NULL AUTO_INCREMENT, '
        . 'firstname text, '
        . 'lastname text, '
        . 'company text, '
        . 'email text, '
        . 'phone text, '
        . 'website text, '
        . 'referred text, '
        . 'details text, '
        . 'PRIMARY KEY(entryID))');
    $result = $stmt->execute();
    # [END create_tables]
    if (false === $result) {
        return sprintf("Error: %s\n", $stmt->errorInfo()[2]);
    } else {
        return 'Tables created';
    }
});
return $app;