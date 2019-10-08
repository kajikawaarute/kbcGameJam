/*!
 * @brief	�X�P���g���G�N�X�|�[�^�[�B
 */
 
pluginManager.loadClass FBXIMPORTER 
pluginManager.loadClass FbxExporter

--�I�u�W�F�N�g�p�����[�^�B
struct ObjectParam(
	objName,
	bindPose,
	invBindPose,
	parentId,
	n
)
--�A�j���[�V�����L�[�t���[��
struct KeyFrame(
	boneId,
	t,
	localTransform
)
--�A�j���[�V�����N���b�v
struct AnimationClip(
	animClipName,		--�A�j���[�V�����N���b�v��
	keyFrames = #()		--�L�[�t���[���̃��X�g
)
--�I�u�W�F�N�g�p�����[�^�̔z��B
g_objectParams = #()

startFrame = 0
endFrame = 0

rollout tkExporter "tkExporter" width:194 height:248
(
	editText 'animClipStartFrame' "" pos:[90,427] width:58 height:21 align:#left
	label 'lbl1' "start frame" pos:[22,430] width:60 height:16 align:#left
	groupBox 'grp1' "Animation clip" pos:[14,401] width:147 height:134 align:#left
	button 'btn_saveAnimationClip' "Save" pos:[27,496] width:120 height:28 align:#left
	label 'lbl2' "end frame" pos:[22,461] width:60 height:16 align:#left
	editText 'animClipEndFrame' "" pos:[90,459] width:58 height:21 align:#left
	button 'btn_saveSkeleton' "Save Skeleton" pos:[22,364] width:120 height:28 align:#left
	label 'lbl3' "Label" pos:[33,423] width:0 height:0 align:#left
	groupBox 'grp5' "FBX" pos:[13,13] width:145 height:109 align:#left
	button 'btn_save_fbx' "Save" pos:[27,33] width:120 height:28 align:#left
	groupBox 'grp10' "Level" pos:[13,135] width:145 height:189 align:#left
	button 'btn_load_locObject' "Load Object" pos:[26,215] width:120 height:28 align:#left
	editText 'levelName' "" pos:[23,181] width:120 height:24 align:#left
	label 'lbl4' "edit level name" pos:[23,160] width:121 height:16 align:#left
	button 'SaveLoc' "Save Level" pos:[26,285] width:120 height:28 align:#left
	groupBox 'grp6' "Animation" pos:[3,338] width:164 height:200 align:#left
	button 'btn_copy_locObject' "Copy Object" pos:[26,249] width:120 height:28 align:#left
	button 'btn_save_selected_fbx' "Save Selected" pos:[27,79] width:120 height:28 align:#left
	
	on  tkExporter open do
	(
		levelName.text = "level00"
	)
	
	/*
	 *  �o�͂���m�[�h�̏����\�z�B
	 */
	fn BuildOutputNodeInfo n parentId= 
	(
		objParam = ObjectParam "" Matrix3 Matrix3 -1 Node
		objParam.objName = n.name
		objParam.bindPose = n.transform
		objParam.invBindPose = inverse n.transform
		objParam.n = n
		if n.parent == undefined then(
			--�e�����Ȃ�
			objParam.parentId = -1
		)else(
			--�e������
			objParam.parentId = parentId
		)

		append g_objectParams objParam
		parentId = g_objectParams.count-1
		--�q�����B
		for child in n.children do(
			BuildOutputNodeInfo child parentId
		)
	)
	/*
	 *  �X�P���g���̕ۑ��B
	*@param[in]  filepath		�ۑ�����t�@�C���p�X�B
	 */
	fn SaveSkeletonFilePath filepath = 
	(
		file = fopen filepath "wb"
			
		try(
			--�w�b�_�[���o��
			WriteLong file g_objectParams.count
			
			for o in g_objectParams do (
				
				WriteByte file o.objName.count
				WriteString file o.objName
				WriteLong file o.parentId
				--�o�C���h�|�[�Y���o�́B
				for i = 1 to 4 do(
					WriteFloat file o.bindPose[i].x
					WriteFloat file o.bindPose[i].y
					WriteFloat file o.bindPose[i].z
				)
				--�o�C���h�|�[�Y�̋t�����o�́B
				for i = 1 to 4 do(
					WriteFloat file o.invBindPose[i].x
					WriteFloat file o.invBindPose[i].y
					WriteFloat file o.invBindPose[i].z
				)
			)
		)catch(
			Messagebox "�t�@�C���̕ۑ��Ɏ��s���܂���"
		)
		FClose file
	)
	/*
	 *  �X�P���g���̕ۑ��B
	 */
	fn SaveSkeleton = 
	(
		filepath = getSaveFileName caption:"" types: "skeleton (*tks)|*.tks|All Files (*.*)|*.*|"
		
		if filepath != undefined then
		(
			SaveSkeletonFilePath filepath
		)
	)
	/*
	 * ���x���f�[�^��ۑ��B
	 */
	fn SaveLevel = 
	(
		filepath = getSaveFileName caption:"" types: "level (*.tkl)|*.tkl|All Files (*.*)|*.*|"
		
		if filepath != undefined then
		(
			
			file = fopen filepath "wb"
			
			try(
				--�w�b�_�[���o��
				WriteLong file g_objectParams.count
				
				for o in g_objectParams do (
					
					WriteByte file o.objName.count
					WriteString file o.objName
					WriteLong file o.parentId
					--�o�C���h�|�[�Y���o�́B
					for i = 1 to 4 do(
						WriteFloat file o.bindPose[i].x
						WriteFloat file o.bindPose[i].y
						WriteFloat file o.bindPose[i].z
					)
					--�o�C���h�|�[�Y�̋t�����o�́B
					for i = 1 to 4 do(
						WriteFloat file o.invBindPose[i].x
						WriteFloat file o.invBindPose[i].y
						WriteFloat file o.invBindPose[i].z
					)
				)
			)catch(
				Messagebox "�t�@�C���̕ۑ��Ɏ��s���܂���"
			)
			FClose file
		)
	)
	/*
	 *  �A�j���[�V�����N���b�v�̕ۑ��B
	 */
	fn SaveAnimationClip=
	(
		filepath = getSaveFileName caption:"" types: "animation clip (*tka)|*.tka|All Files (*.*)|*.*|"

		if filepath != undefined then
		(
			
			numKey = endFrame - startFrame + 1
			if numKey <= 0 then(
				--1�t���[�������o���B
				endFrame = startFrame
				numKey = 1
			)
			deltaTime = 1.0/30
			keyTime = 0.0
			
			numKey *= g_objectParams.Count
			matTransList = #()
			matRotList = #()

			file = fopen filepath "wb"
			--�w�b�_�[���o��
			WriteLong file numKey
			--�A�j���[�V�����C�x���g�̐����o��
			numNoteTrack = numNoteTracks selection[1]

			if numNoteTrack > 0 then(
				--�m�[�g�L�[�̐����o��
				nt = getNoteTrack selection[1] 1
				WriteLong file nt.keys.count
				for k in nt.keys do(
					--�C�x���g���������鎞�Ԃ��o��
					if k.time >= numKey then(
						exit
					)
					invokeTime = k.time * deltaTime
					
					WriteFloat file invokeTime
					WriteLong file k.value.count
					WriteString file k.value
				)
			)else(
				WriteLong file 0
			)
			
			fclose file
			--�A�j���[�V�����̏����o�́B
			slidertime=startFrame

			file = fopen filepath "ab"
			
			for i=startFrame to endFrame do(
				boneId = 0
				keyTime = (i - startFrame) * deltaTime
				
				for o in g_objectParams do (
					n = o.n

					--�o��
					WriteLong file boneId -- ��ID
					WriteFloat file keyTime -- ����
					
					--�{�[�����[�J���s��ɕϊ�����B
					
					transformMatrix = Matrix3 1
					if n.parent == undefined then(
						transformMatrix =n.transform
					)else(
						transformMatrix = n.transform * inverse n.parent.transform
					)
					for i = 1 to 4 do(
						
						WriteFloat file transformMatrix[i].x
						WriteFloat file transformMatrix[i].y
						WriteFloat file transformMatrix[i].z
					)
					boneId +=1
					
				)
				slidertime += 1
			)
			
			fclose file

		)
	)
	/*
	 *  �X�P���g���̏o�͂̃{�^���������ꂽ�Ƃ��̏����B
	 */
	on btn_saveSkeleton pressed do
	(
		if selection[1] == undefined then(
			Messagebox "�o�͂���X�P���g���̃��[�g�̃I�u�W�F�N�g��I�����ĉ������B�B�B"
		)else(
			g_objectParams = #()
			--�A�j���[�V�������Ԃ�0�ɂ���B
			animationRange = interval 0 animationRange.end
			slidertime = 0
			at time 0(
				--�A�j���[�V�����i�s���̏����B
				BuildOutputNodeInfo selection[1] -1
				SaveSkeleton()
			)
		)
	)
	/*
	* Level��ۑ��B
	*/
	on SaveLoc pressed do
	(
		--���ݕҏW���̃��[�g�̃��x�����擾�B
		editLevelObj = getNodeByName levelName.text
		if editLevelObj == undefined then(
			Messagebox "�ۑ����郌�x�������݂��܂���B"
		)else(
			select editLevelObj
		
			--�X�P���g���Ƃ��ĕۑ��B
			g_objectParams = #()
			--�A�j���[�V�������Ԃ�0�ɂ���B
			animationRange = interval 0 animationRange.end
			slidertime = 0
			at time 0(
				--�A�j���[�V�����i�s���̏����B
				BuildOutputNodeInfo selection[1] -1
				SaveLevel()
			)
		)
	)
		/*
	 *  �X�L�����f�B�t�@�C�A���ݒ肳��Ă���m�[�h����������A���̃m�[�h�Ɋ��蓖�Ă��Ă���X�P���g���̃��[�g���擾�B
	 */
	fn GetSkeletonRoot nodes =
	(
		for p in nodes do
		(
			--�X�L�����f�B�t�@�C�A���擾�B
			skinMod = p.modifiers[skin]
			
			if skinMod != undefined then(
				--�X�L�����������B
				clearSelection()
				max modify mode
				select p
				modPanel.setCurrentObject skinMod
				numBone = skinOps.GetNumberBones( skinMod )
				if numBone > 0 then(
					--bone����������������
					boneName = skinOps.GetBoneName skinMod 1 1 
					--���O����m�[�h��I��
					boneNode = getNodebyName(boneName)
					if boneNode != undefined  then (
						--�X�P���g���̃��[�g���������邼
						while boneNode.parent != undefined  do(
							boneNode = boneNode.parent
						)
						--���[�g��Ԃ���B
						return boneNode
					)
				)
			)
		)
		return undefined
	)
	/*
	 *  �A�j���[�V�����N���b�v�̕ۑ��̃{�^���������ꂽ�Ƃ��̏����B
	 */
	on btn_saveAnimationClip pressed do
	(
		--�Ƃ肠�����S�N���b�v�o�͂���B
		skeletonRoot = GetSkeletonRoot objects
		
		if skeletonRoot == undefined  then(
			--�V�[���ɃX�L�����f�B�t�@�C�A��������Ȃ������B
			if selection[1] == undefined  then(
				Messagebox "�X�P���g���̃��[�g�̃I�u�W�F�N�g�̎������ʂ��ł��܂���ł����B\n�X�P���g���̃��[�g�̃I�u�W�F�N�g��I�����ăA�j���[�V�����N���b�v��ۑ����Ă��������B\n"
				return 0
			)
			skeletonRoot = selection[1]
		)
		g_objectParams = #()
		--�A�j���[�V�������Ԃ�0�ɂ���B
		startFrame = animClipStartFrame.text as integer
		endFrame = animClipEndFrame.text as integer
		animationRange = interval startFrame endFrame
		slidertimer = 0
		animate on(
			--�A�j���[�V�����i�s���̏����B
			BuildOutputNodeInfo skeletonRoot -1
			try(
				SaveAnimationClip()
			)catch(
				messageBox "�t�@�C���̕ۑ��Ɏ��s���܂���"
			)
		)
	)
	
	function selectHierarchy =
    (
		for p in selection do
		(
			if p.children != undefined do
			(
				selectmore p.children
			)
		)
    )
    
	/*
	 *�@�z�u����I�u�W�F�N�g���R�s�[
	 */
	on btn_copy_locObject pressed do
	(
		if selection.count == 0  then(
			Messagebox "�R�s�[����I�u�W�F�N�g��I�����Ă��������B"
		)else(
			selectHierarchy()
			parentObj = copy selection[1]
			parentObj.name = selection[1].name
			for obj in 2 to selection.count do (
				cloneObj = copy selection[obj]
				cloneObj.name = selection[obj].name
				cloneObj.parent = parentObj
				parentObj = merge( parentObj cloneObj )
				deselect cloneObj
			)
			select parentObj
		)
	)
	/*
	 * �z�u����I�u�W�F�N�g�̃��[�h�B
	 */
	on btn_load_locObject pressed do
	(
		
		if  levelName.text == "" then(
			Messagebox "�ҏW���郌�x���̖��O����͂��ĉ������B"
		)else(
			filepath = getOpenFileName caption:"" types: "fbx (*fbx)|*.fbx|All Files (*.*)|*.*|"
			if filepath != undefined then(
				editLevelObj = getNodeByName levelName.text
				if editLevelObj == undefined then(
					--�_�~�[�����B
					editLevelObj = Dummy()
					editLevelObj.name = levelName.text
				)
				
				FBXImporterSetParam "ScaleConversion" false
				FBXImporterSetParam "UpAxis" "Z"
				ImportFile filepath #noPrompt
				importObj = $
		
				filename = getFilenameFile filepath
				
				--�S�Ă�ҏW�\�|���S���ɕϊ�����B
				delObjArray = #()
				for i=1 to $selection.count do
				(
					p = convertToMesh($selection[i]);
					--�ҏW�\�|���S���ɕϊ��ł��Ȃ������ꍇ�́A�폜���X�g�ɐςށB
					if p == undefined then(
						append delObjArray $selection[i]
					)
	
				)
				--�ҏW�\�|���S���ɕϊ��ł��Ȃ������I�u�W�F�N�g���폜�B
				for i=1 to delObjArray.count do
				(
					delete delObjArray[i]
				)
				parentBox = box length:1 width:1 height:1
				p = convertToMesh(parentBox)
				importObj.parent = parentBox
				select p
				selectMore $.children
				--�����B
				while  $selection.count>1 do
				(
					attach p $selection[$selection.count];
				)

				--�_�~�[�����x���̉��ɂۂ����ƂȁB
				$selection[1].pivot = Point3 0 0 0
				selection[1].name = filename
				$selection[1].parent = editLevelObj
			)
		)
	)
	/*
	 *  FBX�o�͗p�̐ݒ���s���B
	 */
	fn SetupFbxExportSettings = 
	(
		--���ɂ��I�v�V�������K�v�Ȃ�ǉ����Ă����Ă��������B
		FBXExporterSetParam "ResetExport"
		FBXExporterSetParam "ScaleFactor" 1.0
		FBXExporterSetParam "UpAxis" "Z"
		FBXExporterSetParam "TangentSpaceExport" true
		FBXExporterSetParam "Triangulate" true
		FBXExporterSetParam "ASCII" true
	)
	/*
	 *  �}�e���A�����\���Ă��Ȃ��m�[�h���Ȃ����`�F�b�N���s���B
	 */
	fn CheckMaterial nodes =
	(
		for p in nodes do
		(
			meshCount = GetTriMeshFaceCount(p)
			if classof( p ) == BoneGeometry do(
				--�����̓{�[��
				meshCount[1] = 0
				meshCount[2] = 0
			)
			if meshCount[1] > 0 do
			(
				--���b�V��������B
				if p.material == undefined do
				(
					--�}�e���A���������Ă��Ȃ��B
					errorMessage = "�G���[\n " + p.name + "�Ƀ}�e���A�������蓖�Ă��Ă��Ȃ����ߏo�͂ł��܂���B\n"+ "�}�e���A�������蓖�ĂĂ��������B\n"
					messagebox errorMessage
					return false				
				)
			)
		)
		return true
	)

	/*
	 *  �X�L�����f�B�t�@�C�A���ݒ肳��Ă���m�[�h����������A�X�P���g�����o�͂���B
	 */
	fn TrySaveSkeleton nodes filePath = 
	(
		--�X�P���g����I���o������擾����B
		skeletonRoot = GetSkeletonRoot nodes
		if skeletonRoot != undefined  then(
			
			--�X�P���g����ۑ�����B
			g_objectParams = #()
			--�A�j���[�V�������Ԃ�0�ɂ���B
			animationRange = interval 0 animationRange.end
			slidertime = 0
			at time 0(
				--�A�j���[�V�����i�s���̏����B
				BuildOutputNodeInfo skeletonRoot -1
				--�t�@�C���p�X�̊g���q��tks�ɕύX����B
				extPos = findString filepath "."
				filepath = replace filepath extPos 4 ".tks"
				--�ۑ����\�B
				SaveSkeletonFilePath filepath
			)
		)
	)
	/*!
	 * @brief	FBX��Save�̃{�^���������ꂽ�Ƃ��̏����B
	 */
	on btn_save_fbx pressed do
	(
		if CheckMaterial(objects) then (
			SetupFbxExportSettings()
			
			filepath = getSaveFileName caption:"" types: " (*.fbx)|*.fbx|All Files (*.*)|*.*|"
			if filepath != undefined then(
				exportFile(filepath) #noPrompt
			)
			--�X�L�����f�B�t�@�C�A������ꍇ�ɃX�P���g���f�[�^��ۑ�����B
			TrySaveSkeleton objects filepath
		)
	)
	/*!
	 * @brief	FBX��Save Selected�̃{�^���������ꂽ�Ƃ��̏����B
	 */
	on btn_save_selected_fbx pressed do
	(
		
		if CheckMaterial(selection) then (
			SetupFbxExportSettings()
			filepath = getSaveFileName caption:"" types: " (*.fbx)|*.fbx|All Files (*.*)|*.*|"
			if filepath != undefined then(
				exportFile(filepath) #noPrompt selectedOnly:true
			)
			--�X�L�����f�B�t�@�C�A������ꍇ�ɃX�P���g���f�[�^��ۑ�����B
			TrySaveSkeleton selection filepath
		)
	)
)
addrollout tkExporter style:#(#style_titlebar, #style_sysmenu)