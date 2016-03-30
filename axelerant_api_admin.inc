<?php
/**
 * @file
 * axelerant_api_admin.inc
 */

/**
 * page callback function for /page_json/%siteApiKey/%nid
 *
 * @param $apiKey
 * @param $pageId
 *
 * @return json data
 */
function getPageDataInJsonFormat($apiKey, $pageId)
{
    $response = [];

    if (variable_get('siteapikey') == trim($apiKey)) {

        if (isPage($pageId)) {
            $response['page'] = node_load($pageId);
        } else {
            $response['message'] = 'invalid nid';
        }

    } else {
        $response['message'] = 'access denied';
    }

    return drupal_json_output($response);
}