<?php

/**
 * @file
 * Provide views data for entity_delete_log.module.
 */

/**
 * Implements hook_views_data().
 */
function entity_delete_log_views_data() {
  $data = [];
  $data['entity_delete_log'] = [];
  $data['entity_delete_log']['table'] = [
    'group' => t('Entity Delete Log'),
    'provider' => 'entity_delete_log',
    'base' => [
      'field' => 'entity_delete_log_id',
      'title' => t('Entity Delete Log'),
      'help' => t('The Entity Delete Log Table'),
    ],
  ];

  $data['entity_delete_log']['entity_delete_log_id'] = [
    'title' => t('Entity Delete Log ID'),
    'help' => t('The Entity Delete Log ID'),
    'field' => [
      'id' => 'numeric',
    ],
  ];

  $data['entity_delete_log']['entity_id'] = [
    'title' => t('Entity ID'),
    'help' => t('The Entity ID'),
    'field' => [
      'id' => 'numeric',
    ],
  ];

  $data['entity_delete_log']['entity_type'] = [
    'title' => t('Entity Type'),
    'help' => t('The Entity Type'),
    'field' => [
      'id' => 'standard',
    ],
    'filter' => [
      'id' => 'string',
    ],
    'sort' => [
      'id' => 'standard',
    ],
  ];

  $data['entity_delete_log']['entity_bundle'] = [
    'title' => t('Entity Bundle'),
    'help' => t('The Entity Bundle'),
    'field' => [
      'id' => 'standard',
    ],
    'filter' => [
      'id' => 'string',
    ],
    'sort' => [
      'id' => 'standard',
    ],
  ];

  $data['entity_delete_log']['entity_title'] = [
    'title' => t('Entity Title'),
    'help' => t('The Entity Title'),
    'field' => [
      'id' => 'standard',
    ],
    'filter' => [
      'id' => 'tring',
    ],
    'sort' => [
      'id' => 'standard',
    ],
  ];

  $data['entity_delete_log']['author'] = [
    'title' => t('Author'),
    'help' => t("The User ID of the entity's author"),
    'field' => [
      'id' => 'user_data',
    ],
    'relationship' => [
      'title' => t('Author User Account'),
      'label' => t('Author User Account'),
      'help' => t('The user account for the entity author'),
      'base' => 'users_field_data',
      'base field' => 'uid',
      'relationship field' => 'author',
      'id' => 'standard',
    ],
    'filter' => [
      'id' => 'user_name',
    ],
    'sort' => [
      'id' => 'standard',
    ],
  ];

  $data['entity_delete_log']['revisions'] = [
    'title' => t('Revisions'),
    'help' => t('The number of revisions for the entity'),
    'field' => [
      'id' => 'numeric',
    ],
    'filter' => [
      'id' => 'numeric',
    ],
    'sort' => [
      'id' => 'standard',
    ],
  ];

  $data['entity_delete_log']['created'] = [
    'title' => t('Created'),
    'help' => t('The entity creation date'),
    'field' => [
      'id' => 'date',
    ],
    'filter' => [
      'id' => 'date',
    ],
    'sort' => [
      'id' => 'standard',
    ],
  ];

  $data['entity_delete_log']['deleted'] = [
    'title' => t('Deleted'),
    'help' => t('The entity deletion date'),
    'field' => [
      'id' => 'date',
    ],
    'filter' => [
      'id' => 'date',
    ],
    'sort' => [
      'id' => 'standard',
    ],
  ];

  $data['entity_delete_log']['uid'] = [
    'title' => t('User ID'),
    'help' => t('The user ID of the account that deleted the entity'),
    'field' => [
      'id' => 'user_data',
    ],
    'relationship' => [
      'title' => t('Acting User Account'),
      'label' => t('Acting User Account'),
      'help' => t('The user account who deleted the entity'),
      'base' => 'users_field_data',
      'base field' => 'uid',
      'relationship field' => 'uid',
      'id' => 'standard',
    ],
    'filter' => [
      'id' => 'user_name',
    ],
    'sort' => [
      'id' => 'standard',
    ],
  ];

  return $data;
}
