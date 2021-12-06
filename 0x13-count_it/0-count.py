#!/usr/bin/python3
"""recursive function that queries the Reddit API and returns
a count of all hot articles for a given subreddit"""
import requests


def count_words(subreddit, word_list, hot_list=[], after=None):
    """recursive function that queries the Reddit API and returns
    a count of all hot articles for a given subreddit"""
    url = 'https://www.reddit.com/r/{}/hot.json?after={}'.format(subreddit,
                                                                after)
    headers = {'User-Agent': 'custom'}
    r = requests.get(url, headers=headers, allow_redirects=False)
    if r.status_code != 200:
        return 0
    r_json = r.json()
    data = r_json.get('data')
    children = data.get('children')
    after = data.get('after')
    for i in children:
        hot_list.append(i.get('data').get('title'))
    if after is None:
        return 0
    return count_words(subreddit, word_list, hot_list, after)

