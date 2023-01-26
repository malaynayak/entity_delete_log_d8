<?php

namespace Drupal\entity_delete_log\Form;

use Drupal\Core\Entity\ContentEntityType;
use Drupal\Core\Form\ConfigFormBase;
use Drupal\Core\Form\FormStateInterface;
use Symfony\Component\DependencyInjection\ContainerInterface;
use Drupal\Core\Entity\EntityTypeManagerInterface;
use Drupal\Core\Render\Renderer;
use Drupal\Core\Link;
use Drupal\Core\Url;

/**
 * Class EntityDeleteLogSeetingsForm.
 */
class EntityDeleteLogSeetingsForm extends ConfigFormBase {

  /**
   * Drupal\Core\Entity\EntityTypeManagerInterface definition.
   *
   * @var \Drupal\Core\Entity\EntityTypeManagerInterface
   */
  protected $entityTypeManager;

  /**
   * Drupal\Core\Render\Renderer definition.
   *
   * @var \Drupal\Core\Render\Renderer
   */
  protected $renderer;

  /**
   * Constructs a new EntityDeleteLogSeetingsForm object.
   */
  public function __construct(
    EntityTypeManagerInterface $entity_type_manager,
    Renderer $renderer
  ) {
    $this->entityTypeManager = $entity_type_manager;
    $this->renderer = $renderer;
  }

  /**
   * {@inheritdoc}
   */
  public static function create(ContainerInterface $container) {
    return new static(
      $container->get('entity_type.manager'),
      $container->get('renderer')
    );
  }

  /**
   * {@inheritdoc}
   */
  public function getFormId() {
    return 'entity_delete_log_seetings_form';
  }

  /**
   * {@inheritdoc}
   */
  protected function getEditableConfigNames() {
    return [
      'entity_delete_log.settings',
    ];
  }

  /**
   * {@inheritdoc}
   */
  public function buildForm(array $form, FormStateInterface $form_state) {
    $config = $this->config('entity_delete_log.settings');

    // Add some helpful links.
    $help_links = [
      Link::fromTextAndUrl('View the Entity Delete Log README',
          Url::fromUserInput('/' . \Drupal::service('extension.path.resolver')->getPath('module', 'entity_delete_log') . '/README.txt')),
      Link::fromTextAndUrl('View the Entity Delete Logs',
          Url::fromUserInput('/admin/reports/entity-delete-log')),
    ];
    $list = [
      '#theme' => 'item_list',
      '#items' => $help_links,
    ];
    $form['#prefix'] = $this->renderer->render($list);

    // Provide a list of checkboxes for the user to choose which entity
    // types will have delete logging enabled.
    $entity_definitions = array_filter($this->entityTypeManager->getDefinitions(), function ($definition) {
      return ($definition instanceof ContentEntityType) ? TRUE : FALSE;
    });
    $entity_keys = array_keys($entity_definitions);
    $entity_labels = array_map(function ($definition) {
      return $definition->getLabel()->render();
    }, $entity_definitions);

    $form['entity_types'] = [
      '#title' => $this->t('Entity Types to Log'),
      '#type' => 'checkboxes',
      '#options' => array_combine($entity_keys, $entity_labels),
      '#default_value' => ($config->get('entity_types')) ? $config->get('entity_types') : [],
      '#description' => $this->t('Select which entity types will be logged when deleted.'),
    ];

    return parent::buildForm($form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  public function submitForm(array &$form, FormStateInterface $form_state) {
    $this->configFactory->getEditable('entity_delete_log.settings')
      ->set('entity_types', $form_state->getValue('entity_types'))
      ->save();
    parent::submitForm($form, $form_state);
  }

}
