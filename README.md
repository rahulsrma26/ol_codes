Solution to various coding problems
===================================

Fresh initiation on online coding. Code-gems was getting too big also moving to platform independent codes insted of windows only.

---

Using Visual Studio Code
========================
Project intented to work well with [visual studio code](https://code.visualstudio.com/). It's free, open source and available in all major platforms.

Extentions:

* [Code Runner](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner)
* [Python](https://marketplace.visualstudio.com/items?itemName=ms-python.python)
* [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)

Other helpful extentions:

* [Trailing Spaces](https://marketplace.visualstudio.com/items?itemName=shardulm94.trailing-spaces)
* [Todo Tree](https://marketplace.visualstudio.com/items?itemName=Gruntfuggly.todo-tree)

Setting up extentions
---------------------

First change the syntax highlight settings to c++17 or higher

<img src="docs/img/vscode_cpp_settings.png" alt="vscode_cpp_settings" height="100em"/>

For code-runner, edit settings.json file in '.vscode' folder.

<img src="docs/img/vscode_settings_json.png" alt="vscode_settings_json" height="200em"/>

Append these settings into your workspace settings.

```json
{
    "code-runner.executorMap": {
        "cpp": "cd $dir && g++ $fileName -o bin/$fileNameWithoutExt -std=c++17 -O2 -Wall && ./bin/$fileNameWithoutExt"
    },
    "code-runner.fileDirectoryAsCwd": true,
    "code-runner.runInTerminal": true,
    "code-runner.saveFileBeforeRun": true,
    "code-runner.customCommand": "python $workspaceRoot/commands/runner.py main.cpp -std=c++17 -O2 -Wall"
}
```


Using code fetcher script
-------------------------
Run
```sh
    cd JTS
    python ../commands/fetcher.py <problem-url> <code-template>
```
